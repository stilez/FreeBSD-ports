# Created by: Jos� Garc�a Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	xmlcopyeditor
PORTVERSION=	1.2.1.3
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/xml-copy-editor/${PORTNAME}-linux/${PORTVERSION}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Fast validating XML editor

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libxerces-c.so.3:${PORTSDIR}/textproc/xerces-c3 \
		libxslt.so:${PORTSDIR}/textproc/libxslt \
		libaspell.so:${PORTSDIR}/textproc/aspell \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libexpat.so:${PORTSDIR}/textproc/expat2

USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_UNICODE=	yes
USES=		dos2unix gettext gmake iconv libtool
USE_GNOME=	intltool
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libxml2
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib ${ICONV_LIB}

.include <bsd.port.mk>
