# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	authlogic
PORTVERSION=	3.4.6
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Clean, simple, and unobtrusive Ruby authentication solution

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport>=3.2:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-activerecord>=3.2:${PORTSDIR}/databases/rubygem-activerecord \
		rubygem-request_store>=1.0:${PORTSDIR}/devel/rubygem-request_store \
		rubygem-scrypt>=1.2:${PORTSDIR}/security/rubygem-scrypt

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
