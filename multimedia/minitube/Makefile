# $FreeBSD$

PORTNAME=	minitube
DISTVERSION=	3.6.5
CATEGORIES=	multimedia www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	TV-like client for YouTube

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		compiler:c++11-lang gl qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	flaviotordini
GH_TUPLE=	\
		flaviotordini:idle:6aa092da64a011e445bf31cf31c0cd8dda4c64ff:flaviotordini_idle/lib/idle \
		flaviotordini:media:4d55516ac821fe4d019733ccc70e984220b970d1:flaviotordini_media/lib/media \
		flaviotordini:http:79450c8bb7511ad5a05c6e2aec256b7be136c985:flaviotordini_http/lib/http \
		flaviotordini:updater:f78ad7a665b1bb905ae0baff48512c2d88bcaa7d:flaviotordini_updater/lib/updater \
		flaviotordini:js:d8d7cca7b646263a140a48b8596d55f467d13a94:flaviotordini_js/lib/js

USE_GL=		gl
USE_QT=		core dbus declarative gui network script sql widgets \
		buildtools_build imageformats_run sql-sqlite3_run \
		x11extras

QMAKE_ARGS=	QMAKE_LRELEASE=${LRELEASE} \
		DEFINES+=APP_GOOGLE_API_KEY="${MINITUBE_GOOGLE_API_KEY}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USE=	QT=linguisttools_build

post-patch:
# Remove BOM
	@${REINPLACE_CMD} -e '1 s|^.*/|/|g' \
		${WRKSRC}/src/aggregatevideosource.cpp

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/include(locale\/locale.pri)/d' ${WRKSRC}/minitube.pro

.include <bsd.port.mk>
