#import the required modules and classes
import pandas as pd
from sklearn.ensemble import RandomForestRegressor

"""
Note: Data cannot be in strings(text), it has to be in numbers(ex- 0,1,2...)
"""


def predict(array_lat_long_min_max :list[int | float] = [0,0,0,0]):
    result = rfr.predict([array_lat_long_min_max]).item()
    print(result)


# loading the dataset using pandas module
path_of_dataset = "Air_Quality.csv"
data = pd.read_csv(path_of_dataset, skipinitialspace=True)

# drop the NaN rows from the dataset because they are not required
data = data.dropna()


# prints the first 5 rows of the dataset
# print(data.head())


# initializing the class RandomForestRegressor
rfr = RandomForestRegressor()

# creating models
train_value = data[['latitude', 'longitude', 'pollutant_min', 'pollutant_max']] 
target_value = data[['pollutant_avg']]


# print(train_value)
# print(target_value)

rfr.fit(train_value, target_value)

# finding the accuracy
accuracy = rfr.score(train_value,target_value)*100
print(f"The accuracy of this model is {accuracy:0.2f}")

predict([1.55, 25.557, 45 , 88])