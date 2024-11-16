# with open("weather_data.csv") as file:
#     data = file.readlines()

# import csv
#
# with open("weather_data.csv") as data_file:
#     data = csv.reader(data_file)
#     temperatures = []
#     for row in data:
#         if row[1] != "temp":
#             temperatures.append(int(row[1]))
#     print(temperatures)

import pandas
data = pandas.read_csv("weather_data.csv")

# print(data["temp"])

# data_dict = data.to_dict()
# print(data_dict)
#
# temp_list = data["temp"].to_list()
# print(temp_list)
#
# print(sum(temp_list) / len(temp_list))
#
# print(data["temp"].mean())
#
# print(data["temp"].max())
#
# print(data["condition"])
# print(data.condition)

# print(data[data.day == "Monday"])
# print(data[data.temp == data.temp.max()])

monday = data[data.day == "Monday"]
print(monday.condition)

# monday = data[data.day == "Monday"]
# print((monday.temp * 9/5) + 32)




# data_dict = {
#     "students": ["Amy", "James", "Angela"],
#     "scores": [76, 56, 65]
# }
#
# data = pandas.DataFrame(data_dict)
# data.to_csv("new_data.csv")





# import pandas
# data = pandas.read_csv("2018_Central_Park_Squirrel_Census_-_Squirrel_Data_20241113.csv")
#
# gray = len(data[data["Primary Fur Color"] == "Gray"])
# red = len(data[data["Primary Fur Color"] == "Cinnamon"])
# black = len(data[data["Primary Fur Color"] == "Black"])
#
# data_dict = {
#     "Fur Color": ["Gray", "Red", "Black"],
#     "Count": [0,0,0]
# }
#
# data_dict["Count"][0] = gray
# data_dict["Count"][1] = red
# data_dict["Count"][2] = black
#
# new_data = pandas.DataFrame(data_dict)
# new_data.to_csv("squirrel_count.csv")
