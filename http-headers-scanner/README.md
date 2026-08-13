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