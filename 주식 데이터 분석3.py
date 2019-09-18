from collections import Counter
from linear_algebra import distance
from stats import mean
import math, random
import matplotlib.pyplot as plt
import pandas as pd

def raw_majority_vote(labels):
    votes = Counter(labels)
    winner, _ = votes.most_common(1)[0]
    return winner


def majority_vote(labels):
    """assumes that labels are ordered from nearest to farthest"""
    vote_counts = Counter(labels)
    winner, winner_count = vote_counts.most_common(1)[0]
    num_winners = len([count
                       for count in vote_counts.values()
                       if count == winner_count])

    if num_winners == 1:
        return winner  # unique winner, so return it
    else:
        return majority_vote(labels[:-1])  # try again without the farthest


def knn_classify(k, labeled_points, new_point):
    """each labeled point should be a pair (point, label)"""

    # order the labeled points from nearest to farthest
    by_distance = sorted(labeled_points,
                         key=lambda point_label: distance(point_label[0], new_point))

    # find the labels for the k closest
    k_nearest_labels = [label for _, label in by_distance[:k]]

    # and let them vote
    return majority_vote(k_nearest_labels)


cities = []
df = pd.read_csv('./stock_history_added.csv')
i=0
while i < (len(df.index) - 1):
    i = i + 1
    X = df['cv_diff_rate'][i].item()
    y = df['cv3d_diff_rate'][i].item()
    z = df['ud_Nd'][i].item()

    cities.append((X,y,z))

cities = [([longitude, latitude], language) for longitude, latitude, language in cities]


def plot_state_borders(plt, color='0.8'):
    pass

def plot_cities():

    # key is language, value is pair (longitudes, latitudes)
    plots = { 1 : ([], []), 0 : ([], []), -1 : ([], []) }

    # we want each language to have a different marker and color
    markers = { 1 : "o", 0 : "s", -1 : "^" }
    colors  = { 1 : "r", 0 : "b", -1 : "g" }

    for (longitude, latitude), language in cities:
        plots[language][0].append(longitude)
        plots[language][1].append(latitude)

    # create a scatter series for each language
    for language, (x, y) in plots.items():
        plt.scatter(x, y, color=colors[language], marker=markers[language],
                          label=language, zorder=10)

    plot_state_borders(plt)    # assume we have a function that does this

    plt.legend(loc=0)          # let matplotlib choose the location
    plt.axis([-0.15,0.15,-0.1,0.1]) # set the axes
    plt.title("Favorite Programming Languages")
    plt.show()

def classify_and_plot_grid(k=1):
    plots = { 1 : ([], []), 0 : ([], []), -1 : ([], []) }

    # we want each language to have a different marker and color
    markers = { 1 : "o", 0 : "s", -1 : "^" }
    colors  = { 1 : "r", 0 : "b", -1 : "g" }

    for longitude in range(-50, 50):
        for latitude in range(-50, 50):
            predicted_language = knn_classify(k, cities, [longitude, latitude])
            plots[predicted_language][0].append(longitude)
            plots[predicted_language][1].append(latitude)

    # create a scatter series for each language
    for language, (x, y) in plots.items():
        plt.scatter(x, y, color=colors[language], marker=markers[language],
                    label=language, zorder=0)

    plot_state_borders(plt, color='black')  # assume we have a function that does this

    plt.legend(loc=0)  # let matplotlib choose the location
    plt.axis([-50, 50, -50, 50])  # set the axes
    plt.title(str(k) + "-Nearest Neighbor Programming Languages")
    plt.show()


#
# the curse of dimensionality
#

def random_point(dim):
    return [random.random() for _ in range(dim)]


def random_distances(dim, num_pairs):
    return [distance(random_point(dim), random_point(dim))
            for _ in range(num_pairs)]


if __name__ == "__main__":
    # 1. Pllot City
    plot_cities()

    # 2. try several different values for k
    for k in [1, 3, 5, 7, 9, 11, 13, 15, 17]:
        num_correct = 0

        for location, actual_language in cities:

            other_cities = [other_city
                            for other_city in cities
                            if other_city != (location, actual_language)]

            predicted_language = knn_classify(k, other_cities, location)

            if predicted_language == actual_language:
                num_correct += 1

        print(k, "neighbor[s]:", num_correct, "correct out of", len(cities))

    # 3. classfy and plot grid with k = 1, 3, 5
    # classify_and_plot_grid(3)
    #classify_and_plot_grid(1)
    #classify_and_plot_grid(3)
    #classify_and_plot_grid(5)
    #classify_and_plot_grid(7)
    #classify_and_plot_grid(9)

"""

    # 4. dim 1~1000, get the avg distance and min distance
    dimensions = range(1, 101, 5)  # (1,101,1) for graph
    avg_distances = []
    min_distances = []
    min_over_avg = []

    random.seed(0)
    for dim in dimensions:
        distances = random_distances(dim, 10000)  # 10,000 random pairs
        avg_distances.append(mean(distances))  # track the average
        min_distances.append(min(distances))  # track the minimum
        min_over_avg.append(min(distances) / mean(distances))  # track the minimum / mean
        print(dim, min(distances), mean(distances), min(distances) / mean(distances))

    """
"""
    # 5. distance problem when high dim
    plt.plot(avg_distances, label="avg_distances")
    plt.plot(min_distances,label="mindistances")
    plt.legend()
    plt.show()

    # 6. min_over_avg
    plt.plot(min_over_avg)
    plt.show()
"""
