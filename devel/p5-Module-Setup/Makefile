# $FreeBSD$

PORTNAME=	Module-Setup
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for a simple module maker

RUN_DEPENDS=	\
	p5-Class-Trigger>0:${PORTSDIR}/devel/p5-Class-Trigger \
	p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
	p5-File-HomeDir>0:${PORTSDIR}/devel/p5-File-HomeDir \
	p5-libwww>0:${PORTSDIR}/www/p5-libwww \
	p5-Module-Collect>=0.06:${PORTSDIR}/devel/p5-Module-Collect \
	p5-Path-Class>0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Template-Toolkit>=2.20:${PORTSDIR}/www/p5-Template-Toolkit \
	p5-YAML>0:${PORTSDIR}/textproc/p5-YAML \
	p5-Module-Install-AuthorTests>0:${PORTSDIR}/devel/p5-Module-Install-AuthorTests \
	p5-Text-Patch>0:${PORTSDIR}/textproc/p5-Text-Patch
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
