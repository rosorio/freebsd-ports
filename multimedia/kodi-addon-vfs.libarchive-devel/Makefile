# $FreeBSD$

PORTNAME=	vfs.libarchive
DISTVERSION=	1.3.0
DISTVERSIONSUFFIX=	-Matrix
PORTREVISION=	2
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	VFS addon for Kodi to access archives directly

LICENSE=	GPLv2+

BUILD_DEPENDS=	kodi-devel>=19.0.a20200727:multimedia/kodi-devel
LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		liblzo2.so:archivers/lzo2
RUN_DEPENDS=	kodi-devel>=19.0.a20200727:multimedia/kodi-devel

USES=		cmake compiler:c++14-lang libarchive ssl
USE_GITHUB=	yes
GH_ACCOUNT=	xbmc

PLIST_SUB=	SOVERSION=${DISTVERSION}

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} share/kodi/addons/${PORTNAME}/resources/language \
		-name strings.po >> ${TMPPLIST}

.include <bsd.port.mk>
