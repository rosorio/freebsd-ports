# $FreeBSD$

PORTNAME=	webchannel
CATEGORIES=	www devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtWebChannel module

# LICENSE set in Mk/Uses/pyqt.mk

BUILD_DEPENDS=	${PY_ENUM34}
RUN_DEPENDS=	${PY_ENUM34}

USES=		python pyqt:5 qt:5
USE_PYQT=	sip_build core_run gui_run qml_run network_run widgets_run
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core declarative qmake_build gui network webchannel widgets

CONFIGURE_ARGS=	--enable QtWebChannel \
		--no-stubs
PYQT_DIST=	yes

OPTIONS_DEFINE=		API DEBUG
OPTIONS_DEFAULT=	API
OPTIONS_SUB=		yes

API_DESC=		Install QtWebChannel API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

post-install-DEBUG-off:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/PyQt5/QtWebChannel.so

.include <bsd.port.mk>
