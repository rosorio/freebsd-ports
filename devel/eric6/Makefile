# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-qt5-${FLAVOR:U:S/_/-/}
DISTNAME=	${PORTNAME}-nolang-${DISTVERSION}
PORTREVISION=	1
CATEGORIES=	devel python

# Note to MAINTAINER: this should be converted to USES=pyqt, USE_PYQT=[...]
BUILD_DEPENDS+=	${PYQT_PY_RELNAME}-chart>=${PYQT_VERSION}:x11-toolkits/py-qt5-chart@${PY_FLAVOR}
RUN_DEPENDS+=	${PYQT_PY_RELNAME}-chart>=${PYQT_VERSION}:x11-toolkits/py-qt5-chart@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_LIBDIR}/lib-dynload/_sqlite3.so:databases/py-sqlite3@${PY_FLAVOR}

CONFLICTS_INSTALL=	${FLAVORS:N${FLAVOR}:C/^/${PORTNAME}${PKGNAMESUFFIX}-/:C/$/-[0-9]*/}

USES+=		desktop-file-utils python:3.5+ pyqt:5 shebangfix
USE_PYTHON=	flavors
USE_PYQT=	core gui qscintilla2 webengine \
		help_run network_run svg_run sql_run
INSTALL_PY=	install.py -c -f eric6config.freebsd -i ${STAGEDIR}
SHEBANG_FILES=	*.py eric/eric6/*.py eric/scripts/*.py
SUB_FILES=	eric6.desktop
MASTERPORT=	yes

PORTDATA=	*
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include "${.CURDIR}/bsd.eric6.mk"
.include <bsd.port.options.mk>

post-patch:
	${RM} ${WRKSRC}/eric/i18n/*.qm ${WRKSRC}/eric/i18n/*.ts

do-configure:
	${SED}  -e 's,PYTHON_SITELIBDIR,${PYTHON_SITELIBDIR},' \
		-e 's,PREFIX,${PREFIX},' \
		-e 's,DATADIR,${DATADIR},' \
		-e 's,LOCALBASE,${LOCALBASE},' \
		-e 's,DOCSDIR,${DOCSDIR},' \
		-e 's,EXAMPLESDIR,${EXAMPLESDIR},' \
		< ${FILESDIR}/config > ${WRKSRC}/eric6config.freebsd

do-install:
	@(cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_PY})

post-install:
	${INSTALL_DATA} ${WRKDIR}/eric6.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${LN} -sf ${DATADIR:C|${PREFIX}(/share(/pixmaps)?)?||:C|/[^/]+|../|g}eric6/icons/default/eric.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/eric6.png
	@${MKDIR} ${STAGEDIR}${DATADIR}/i18n

.include <bsd.port.mk>
