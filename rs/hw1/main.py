from datetime import date

def exchange(bgn_amount, currency, exchange_date):
    if(currency == 'EUR'):
        result = bgn_amount * 0.511292
    elif(currency == 'TRY'):
        result = bgn_amount * (1.46 + (0.0014 * (date.today() - exchange_date).days))
    return result
    
print(exchange(2, "EUR", date(2020, 10, 14)))
print(exchange(2, "TRY", date(2020, 10, 14)))
