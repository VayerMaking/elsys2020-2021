logs = [
    {"timestamp": "2020-05-11T13:42:50", "status": "error", "countryISO2": "BG"},
    {"timestamp": "2020-05-11T13:43:20", "status": "success", "countryISO2": "UK"},
    {"timestamp": "2020-05-11T13:44:30", "status": "success", "countryISO2": "NZ"},
    {"timestamp": "2020-05-11T13:44:33", "status": "success", "countryISO2": "NZ"},
]


def filter_logs(logs, key, value):
    filtered_log = [d for d in logs if d[key] in value]
    return filtered_log

def top(logs, key, count):
    temp_dict = {}
    temp_list = []
    result = {}

    for log in logs:
        if key in log.keys():
            temp_list.append(log.get(key))

    temp_dict = dict((log, temp_list.count(log) ) for log in temp_list)
    result = dict(sorted(temp_dict.items(), key=lambda x: x[1], reverse=True))
    result = dict(list(result.items())[0: count])

    return result


def complex_filter(logs, filter_params):
    result_list = []
    for log in logs:
        result = filter_params.items() <= log.items()
        if result:
            result_list.append(log)

    return result_list

###################testing#################
#print(complex_filter(logs, {"status": "error", "countryISO2": "BG"}))
#print(complex_filter(logs, {"status": "success"}))
#print(filter_logs(logs, "status","error"))
#print(top(logs, "status", 1))
#print(top(logs, "status", 2))
#print(complex_filter(logs, {}))
#print(complex_filter(logs, {"status": "error", "countryISO2": "NZ"}))
