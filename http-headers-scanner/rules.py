SECURITY_HEADERS = {
    "Strict-Transport-Security": {
        "description": "Forces browsers to use HTTPS instead of HTTP",
        "severity": "High",
    },
    "Content-Security-Policy": {
        "description": "Controls which sources of scripts/images/etc. are allowed to load",
        "severity": "High",
    },
    "X-Frame-Options": {
        "description": "Prevents the page from being embedded in an iframe (clickjacking protection)",
        "severity": "Medium",
    },
    "X-Content-Type-Options": {
        "description": "Stops browsers from guessing content types (MIME sniffing protection)",
        "severity": "Medium",
    },
    "Referrer-Policy": {
        "description": "Controls how much referrer info is sent with outgoing requests",
        "severity": "Low",
    },
    "Permissions-Policy": {
        "description": "Controls which browser features (camera, mic, location) the page can use",
        "severity": "Low",
    },
}

INFO_DISCLOSURE_HEADERS = ("Server", "X-Powered-By")