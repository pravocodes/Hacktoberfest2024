#import the required modules and classes
import pandas as pd

# loading the dataset using pandas module
path_of_dataset = "Air_Quality.csv"
train_data = pd.read_csv(path_of_dataset)

# prints the first 5 rows of the dataset
print(train_data.head()) 