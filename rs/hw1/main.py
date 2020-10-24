from collections import Counter
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
    top_log = dict()
    for log in logs:
        i = 0
        num = 1
        #while i < count:
        top_log[0] = log[key]
        top_log[1] = num
        print(top_log)
        #    i++
        cnt = Counter()
        for word in log:
            cnt[word] += 1

    return cnt

def complex_filter(logs, filter_params):
    filtered_log = list()
    for log in logs:
        for filter_key in filter_params.keys():
            #filtered_log = [d for d in keys if d[key] in keys]
            for log_key in log.keys():
                if log_key == filter_key:
                    filtered_log.append(log.items())
        #print(filtered_log)
    return filtered_log
def complex_filter2(logs, filter_params):
    filtered_log = list()
    for log in logs:
        for log_key, log_value in log.items():
            print("log_key", log_key)
            print("log_value", log_value)
            for filter_key, filter_value in filter_params.items():
                print("filter_key", filter_key)
                print("filter_value", filter_value)
                if log_key == filter_key and log_value == filter_value:
                    filtered_log.append(log)
    return filtered_log
def complex_filter3(logs, filter_params):
    filtered_log_dict = dict()
    filtered_log_list = list()
    for log in logs:
        for filter_key, filter_value in filter_params.items():
            for log_key, log_value in log.items():
                if log_key == filter_key:
                    if log_value == filter_value:
                        filtered_log_dict.update(log)
        filtered_log_list.append(filtered_log_dict)
    return filtered_log_list
print(complex_filter3(logs, {"status": "success", "countryISO2": "NZ"}))
#print(filter_logs(logs, "status","error"))
#print(top(logs, "status", 2))
