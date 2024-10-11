#import the required libraries:-

import pandas as pd
from sklearn.ensemble import RandomForestRegressor
# RandomForestRegressor is useful because it combines all the other models(linear regressions, logistic regressions, etc..) together to make the prediction more accurate.

# NOTE: Data cannot be in strings(text, non-numericals), it has to be in numbers(ex- 0,1,2...)

#function:-
def predict(array_lat_long_min_max :list[int | float] = [0,0,0,0]):
    result = rfr.predict([array_lat_long_min_max]).item()
    print("Average air quality index(pollutant):",result)


# loading the dataset using pandas module:-
path_of_dataset = "Air_Quality.csv" # path of the csv file
data = pd.read_csv(path_of_dataset, skipinitialspace=True)


data = data.dropna() # drop the NaN rows from the dataset because they are not required


# prints the first 5 rows of the dataset:-
# print(data.head())


# initializing the class RandomForestRegressor:-
rfr = RandomForestRegressor()


# creating models:-
features = ['latitude', 'longitude', 'pollutant_min', 'pollutant_max']
train_value = data[features].values # .values is important for not getting any warnings
# the above train value is for the input given by the user for predictions 
target_value = data['pollutant_avg']
# the above target value is for the output which will be predicted


# check for the data in train_value and target_value:-
# print(train_value)
# print(target_value)


# fitting the data:-
rfr.fit(train_value, target_value)

# user input:-
array = list(map(float, input("Enter latitude longitude min_pollutant max_pollutant: ").split(" ")))


# finding the accuracy:-
accuracy = rfr.score(train_value,target_value)*100
print(f"The accuracy score of this model is {accuracy:0.2f}")


# prediction:-
predict(array)
