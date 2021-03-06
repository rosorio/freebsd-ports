# $FreeBSD$

PORTNAME=	cloud-init
PORTVERSION=	20.3
PORTREVISION=	1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	andrey@bsdnir.info
COMMENT=	Init scripts for use on cloud images

LICENSE=	APACHE20 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-Apache2.0
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE-GPLv3

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	currently depends on dmidecode which is x86-only

RUN_DEPENDS=	dmidecode>0:sysutils/dmidecode \
		sudo>0:security/sudo \
		${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>0:devel/py-jsonpatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpointer>0:devel/py-jsonpointer@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	canonical

SHEBANG_FILES=	tools/validate-yaml.py tools/read-dependencies \
		tools/read-version
USE_PYTHON=	autoplist distutils
ETCDIR=		${PREFIX}/etc/cloud

PYDISTUTILS_INSTALLARGS+=	"--init-system=sysvinit_freebsd"

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's|"etc"|"${STAGEDIR}${PREFIX}/etc"|g' ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|g' ${WRKSRC}/cloudinit/settings.py
	@${RM} ${WRKSRC}/sysvinit/freebsd/*.orig

post-build:
	@cd ${WRKSRC} && ${MV} config/cloud.cfg.d/05_logging.cfg config/cloud.cfg.d/05_logging.cfg.sample

.include <bsd.port.mk>
