<?php
/*
 * mdns-repeater.inc
 *
 * part of pfSense (https://www.pfsense.org)
 * Copyright (c) 2009-2015 Rubicon Communications, LLC (Netgate)
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

require_once('config.inc');
require_once('interfaces.inc');
require_once('service-utils.inc');
require_once('util.inc');
 
function mdns-repeater_write_config() {
	global $config;

	// Pull some various values out of config.xml
	if (isset($config['installedpackages']['mdns-repeater']['config'][0])) {
		$mdns-repeater_config = $config['installedpackages']['mdns-repeater']['config'][0];
	} else {
		$mdns-repeater_config = array();
	}
	// Server Options
	$hostname = $config['system']['hostname'];
	$domain = $config['system']['domain'];
	$enable = $mdns-repeater_config['enable'];
	$browsedomains = $mdns-repeater_config['browsedomains'] ?: "local";
	$denyif = $mdns-repeater_config['denyinterfaces'];
	$useipv4 = ($mdns-repeater_config['enable_ipv4']) ? "yes" : "no";
	$useipv6 = ($mdns-repeater_config['enable_ipv6']) ? "yes" : "no";
	$usedbus = ($mdns-repeater_config['disable_dbus']) ? "no" : "yes";
	// Wide Area
	$widearea = ($mdns-repeater_config['enable_wide_area']) ? "yes" : "no";
	// Publishing Options
	$publish = ($mdns-repeater_config['disable_publishing']) ? "yes" : "no";
	$userpublish = ($mdns-repeater_config['disable_user_service_publishing']) ? "yes" : "no";
	$addresspublish = ($mdns-repeater_config['publish_addresses']) ? "yes" : "no";
	$cookie = ($mdns-repeater_config['add_service_cookie']) ? "yes" : "no";
	$hinfopublish = ($mdns-repeater_config['publish_hinfo']) ? "yes" : "no";
	$wspublish = ($mdns-repeater_config['publish_workstation']) ? "yes" : "no";
	$aaaaonv4 = ($mdns-repeater_config['publish_aaaa_on_ipv4']) ? "yes" : "no";
	$aonv6 = ($mdns-repeater_config['publish_a_on_ipv6']) ? "yes" : "no";

	// Process interfaces defined by user to deny.
	if ($denyif) {
		$if = explode(",", $denyif);
		foreach ($if as $i) {
			$ifreal = convert_friendly_interface_to_real_interface_name($i);
			if ($ifreal) {
				$denyinterfaces .= ", " . $ifreal;
			}
		}
	}

function mdns-repeater_write_rcfile() {
	global $config;
	if (isset($config['installedpackages']['mdns-repeater']['config'][0])) {
		$mdns-repeater_config = $config['installedpackages']['mdns-repeater']['config'][0];
	} else {
		$mdns-repeater_config = array();
	}

	$start = "/etc/rc.conf_mount_rw\n";
	$start .= "if [ ! -d /proc/0 ]; then\n";
	$start .= "	/bin/mkdir -p /proc\n";
	$start .= "	/sbin/mount -t procfs procfs /proc\n";
	$start .= "fi\n";
	$start .= "/usr/bin/killall mdns-repeater-daemon >/dev/null 2>&1\n";
	if (!$mdns-repeater_config['disable_dbus']) {
		$start .= "if [ ! -d /var/run/dbus ]; then\n";
		$start .= "        /bin/mkdir /var/run/dbus\n";
		$start .= "        /usr/sbin/chown messagebus:messagebus /var/run/dbus\n";
		$start .= "fi\n";
	}
	$start .= "/sbin/mdns-repeater-daemon -D\n";
	$start .= "/etc/rc.conf_mount_ro\n";

	$stop = "/usr/bin/killall mdns-repeater-daemon >/dev/null 2>&1\n";

	write_rcfile(array(
		"file" => "mdns-repeater-daemon.sh",
		"start" => $start,
		"stop" => $stop
		)
	);
}

function mdns-repeater_sync() {
	global $config;
	conf_mount_rw();

	if (is_service_running("mdns-repeater")) {
		stop_service("mdns-repeater");
	}
	mdns-repeater_write_config();

	// Is package enabled?
	if ($config['installedpackages']['mdns-repeater']['config'][0]['enable']) {
		mdns-repeater_write_rcfile();
		start_service("mdns-repeater");
	} else {
		unlink_if_exists("/usr/local/etc/rc.d/mdns-repeater-daemon.sh");
		if (file_exists("/usr/local/etc/rc.d/dbus")) {
			chmod("/usr/local/etc/rc.d/dbus", 0644);
		}
	}

	conf_mount_ro();
}

function mdns-repeater_upgrade_config() {
	global $config;

	$mdns-repeater_config =& $config['installedpackages']['mdns-repeater']['config'][0];
	if (!is_array($mdns-repeater_config)) {
		$mdns-repeater_config = array();
	}
	$changes = 0;
	// Convert previous disable values to enable ones
	// If broken settings were configured due to lack of validation, just set to defaults
	if (isset($mdns-repeater_config['disable_ipv4']) && isset($mdns-repeater_config['disable_ipv6']) && $mdns-repeater_config['disable_ipv4'] == "on" && $mdns-repeater_config['disable_ipv6'] == "on") {
		$mdns-repeater_config['enable_ipv4'] = "on";
		$mdns-repeater_config['enable_ipv6'] = "on";
		unset($mdns-repeater_config['disable_ipv4']);
		unset($mdns-repeater_config['disable_ipv6']);
		$changes++;
	} elseif (isset($mdns-repeater_config['disable_ipv4']) && $mdns-repeater_config['disable_ipv4'] != "on") {
		$mdns-repeater_config['enable_ipv4'] = "on";
		unset($mdns-repeater_config['disable_ipv4']);
		$changes++;
	} elseif (isset($mdns-repeater_config['disable_ipv6']) && $mdns-repeater_config['disable_ipv6'] != "on") {
		$mdns-repeater_config['enable_ipv6'] = "on";
		unset($mdns-repeater_config['disable_ipv6']);
		$changes++;
	}
	if ($changes > 0 ) {
		write_config("[mdns-repeater] Upgraded old package configuration.");
	}
}

?>
