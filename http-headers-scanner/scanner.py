import requests

def fetch_headers(url):
    try:
        response = requests.get(url, timeout=5)
        return response.headers
    except requests.RequestException as e:
        print(f"Error fetching headers for {url}: {e}")
        return None


if __name__ == "__main__":
    print(fetch_headers("https://example.com")) 