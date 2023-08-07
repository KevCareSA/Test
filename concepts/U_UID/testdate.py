from datetime import datetime, date, time, timedelta, timezone, tzinfo


# today = datetime(2023, 8, 7, 12, 30, 2)
current_time = datetime.now()
# thisyear = today_accurate.year
# print(today)
# print(today_accurate)
# print(thisyear)
# print(today_accurate.month)

# parsed_datetime = datetime.strptime('2023-08-07 12:30:00', '%Y-%m-%d %H:%M:%S')
# print(parsed_datetime.year)


formatted_datetime = current_time.isoformat()
print(formatted_datetime)
