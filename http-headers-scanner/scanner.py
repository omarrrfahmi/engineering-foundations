import requests

def fetch_headers(url, timeout=5):
    if not url.startswith(("http://", "https://")):
        url = "https://" + url

    try:
        response = requests.get(url, timeout=timeout)
        return {
            "success": True,
            "status_code": response.status_code,
            "headers": dict(response.headers),
            "error": None,
        }
    except requests.exceptions.RequestException as e:
        return {
            "success": False,
            "status_code": None,
            "headers": {},
            "error": str(e),
        }