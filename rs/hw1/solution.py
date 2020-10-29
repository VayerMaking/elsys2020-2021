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
