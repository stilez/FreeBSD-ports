# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tinyatom
PORTVERSION=	0.3.6
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Small and easy to use ruby Atom feed generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-builder32>=0:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-public_suffix>=0:${PORTSDIR}/dns/rubygem-public_suffix

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
