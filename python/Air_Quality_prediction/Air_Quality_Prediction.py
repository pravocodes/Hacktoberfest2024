#import the required modules and classes
import pandas as pd
from sklearn.ensemble import RandomForestRegressor, AdaBoostRegressor


# loading the dataset using pandas module
path_of_dataset = "Air_Quality.csv"
train_data = pd.read_csv(path_of_dataset)

# prints the first 5 rows of the dataset
print(train_data.head())

# initializing the class RandomForestRegressor
rfr = RandomForestRegressor()

# creating models
target_value = train_data['pollutant_avg']
train_model = train_data.drop('pollutant_avg', axis=1) 

print(train_model)
print(target_value)