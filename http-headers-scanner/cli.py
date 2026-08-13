import sys
from scanner import fetch_headers
from rules import SECURITY_HEADERS, INFO_DISCLOSURE_HEADERS


def analyze(headers):
    rows = []

    for header, info in SECURITY_HEADERS.items():
        status = "Present" if header in headers else "MISSING"
        rows.append([header, status, info["severity"], info["description"]])

    for header in INFO_DISCLOSURE_HEADERS:
        if header in headers:
            rows.append([header, "EXPOSED", "Info", f"Server discloses: {headers[header]}"])

    return rows


def print_table(rows):
    column_titles = ["Header", "Status", "Severity", "Notes"]
    all_rows = [column_titles] + rows

    col_widths = [
        max(len(str(row[i])) for row in all_rows)
        for i in range(len(column_titles))
    ]

    def print_row(row):
        print("  ".join(str(cell).ljust(col_widths[i]) for i, cell in enumerate(row)))

    print_row(column_titles)
    print_row(["-" * w for w in col_widths])
    for row in rows:
        print_row(row)


def main():
    if len(sys.argv) < 2:
        print("Usage: python cli.py <url>")
        sys.exit(1)

    url = sys.argv[1]
    result = fetch_headers(url)

    if not result["success"]:
        print(f"Could not fetch {url}: {result['error']}")
        sys.exit(1)

    print(f"\nScanning: {url}")
    print(f"Status code: {result['status_code']}\n")

    print_table(analyze(result["headers"]))


if __name__ == "__main__":
    main()