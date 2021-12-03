import sys

oxygen_report = [row.strip() for row in sys.stdin]
co2_report = oxygen_report.copy()

def filter_report(report, pos, most=True):
    if len(report) == 1:
        return report
    sum = 0
    for row in report:
        sum = sum + (1 if row[pos] == "1" else -1)
    most_common = "1" if sum >= 0 else "0"
    return [row for row in report if (row[pos] == most_common if most else row[pos] != most_common)]


for i in range(len(oxygen_report[0])):
    oxygen_report = filter_report(oxygen_report, i)

for i in range(len(co2_report[0])):
    co2_report = filter_report(co2_report, i, False)


oxygen = int(oxygen_report[0],2)
co2 = int(co2_report[0],2)

print(oxygen*co2)
