# HTTP Headers Scanner

A simple command-line tool that scans a website's HTTP response headers 
and checks them against common security best practices.

## What it checks

- **Security headers**: Strict-Transport-Security, Content-Security-Policy, 
  X-Frame-Options, X-Content-Type-Options, Referrer-Policy, Permissions-Policy
- **Info-disclosure headers**: Server, X-Powered-By (headers that leak 
  details about the server stack, which attackers can use for recon)

## Setup

```bash
# Clone the repo and cd into this folder
cd http-headers-scanner

# Create and activate a virtual environment
python -m venv venv
.\venv\Scripts\Activate.ps1      # Windows PowerShell
# source venv/bin/activate       # macOS/Linux

# Install dependencies
pip install -r requirements.txt
```

## Usage

```bash
python cli.py <url>
```

Example:
```bash
python cli.py example.com
```

Sample output:
 
 Scanning: https://example.com
    Status code: 200

    Header                       Status    Severity  Notes
    ---------------------------  --------  --------  -----------------------------------------
    Strict-Transport-Security    MISSING   High      Forces browsers to use HTTPS instead of HTTP
    Content-Security-Policy      MISSING   High      Controls which sources of scripts/images/etc. are allowed to load
    X-Frame-Options              MISSING   Medium    Prevents the page from being embedded in an iframe (clickjacking protection)
    X-Content-Type-Options       MISSING   Medium    Stops browsers from guessing content types (MIME sniffing protection)
    Referrer-Policy              MISSING   Low       Controls how much referrer info is sent with outgoing requests
    Permissions-Policy           MISSING   Low       Controls which browser features the page can use
    Server                       EXPOSED   Info      Server discloses: cloudflare

## How it works

- `scanner.py` — sends an HTTP GET request and returns the response headers
- `rules.py` — the checklist of headers to look for, with severity and explanation
- `cli.py` — command-line entry point that runs the scan and prints results as a table

## Project status

Built as a self-study project to practice Python, the `requests` library,
and web security fundamentals (OWASP secure headers).

## Possible future improvements

- JSON/CSV export
- Scan multiple URLs from a file
- Overall letter grade (A–F) based on how many checks pass