# Created by: Rod Person <rodperson@rodperson.com>
# $FreeBSD$

PORTNAME=	spyder
PORTVERSION=	2.3.7
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rodperson@rodperson.com
COMMENT=	Scientific PYthon Development EnviRonment, an alternative to IDLE

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtWebKit.so:${PORTSDIR}/www/py-qt4-webkit \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:${PORTSDIR}/net/py-qt4-network

USES=		desktop-file-utils python
USE_PYTHON=	autoplist distutils
MAKE_ENV=	USE_SETUPTOOLS=1

USE_GITHUB=	yes
GH_ACCOUNT=	spyder-ide

DOCSDIR=	${PYTHON_SITELIBDIR}/spyderlib
PORTDOCS=	doc

OPTIONS_DEFINE=	DOCS
OPTIONS_GROUP=	RECOMMENDED OPTIONAL
OPTIONS_GROUP_RECOMMENDED=	IPYTHON MATPLOT NUMPY PSUTIL PYFLAKES ROPE SCIPY SPHINX
OPTIONS_GROUP_OPTIONAL=	JEDI PANDAS PEP8 PYGMENTS PYLINT SYMPY

IPYTHON_DESC=	IPython Console integration
JEDI_DESC=	(Experimental) Editor's code completion, go-to-definition and help
MATPLOT_DESC=	Interactive data plotting in the consoles
NUMPY_DESC=	N-dimensional arrays
PANDAS_DESC=	View and edit DataFrames and Series in the Variable Explorer
PEP8_DESC=	Real-time code style analysis on the Editor
PSUTIL_DESC=	CPU and memory usage info in the status bar
PYFLAKES_DESC=	Real-time code analysis on the Editor
PYGMENTS_DESC=	Syntax highlighting for Matlab, Julia and other file types
PYLINT_DESC=	Static code analysis
ROPE_DESC=	Editor's code completion, go-to-definition and help
SCIPY_DESC=	Signal/image processing
SPHINX_DESC=	Rich text help on the Object Inspector
SYMPY_DESC=	Symbolic mathematics in the IPython Console

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0.6:${PORTSDIR}/textproc/py-sphinx
IPYTHON_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=1.0:${PORTSDIR}/devel/ipython \
	${PYTHON_PKGNAMEPREFIX}pyzmq>=2.1.11:${PORTSDIR}/net/py-pyzmq
JEDI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jedi>=0.8.1:${PORTSDIR}/devel/py-jedi
MATPLOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=1.0:${PORTSDIR}/math/py-matplotlib
NUMPY_RUN_DEPENDS=	${PYNUMPY}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0.13.1:${PORTSDIR}/math/py-pandas
PEP8_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pep8>=0.6:${PORTSDIR}/devel/pep8
PSUTIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0.3:${PORTSDIR}/sysutils/py-psutil
PYFLAKES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyflakes>=0.5:${PORTSDIR}/devel/py-pyflakes
PYGMENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:${PORTSDIR}/textproc/py-pygments
PYLINT_RUN_DEPENDS=	pylint${PYTHON_PKGNAMESUFFIX}>=0.25:${PORTSDIR}/devel/pylint
ROPE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rope>=0.9.2:${PORTSDIR}/devel/py-rope
SCIPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scipy>0:${PORTSDIR}/science/py-scipy
SPHINX_RUN_DEPENDS=	${DOCS_BUILD_DEPENDS}
SYMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>=0.7.3:${PORTSDIR}/math/py-sympy

post-patch:
	@${REINPLACE_CMD} -e "s|'linux'|'${OPSYS:tl}'|" \
		${WRKSRC}/setup.py \
		${WRKSRC}/spyderlib/spyder.py

.include <bsd.port.mk>
