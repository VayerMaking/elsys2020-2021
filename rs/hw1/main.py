logs = [
    {"timestamp": "2020-05-11T13:42:50", "status": "error", "countryISO2": "BG"},
    {"timestamp": "2020-05-11T13:43:20", "status": "success", "countryISO2": "UK"},
    {"timestamp": "2020-05-11T13:44:30", "status": "success", "countryISO2": "NZ"},
]


def filter_logs(logs, key, value):
    filtered_log = [d for d in logs if d[key] in value]
    return filtered_log



print(filter_logs(logs, "status","error"))
