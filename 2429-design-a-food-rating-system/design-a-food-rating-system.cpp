class FoodRatings {
public:
    unordered_map<string,string> foodCuisine;
    unordered_map<string,int> foodRating;
    unordered_map<string,set<pair<int,string>>> cuisineRatingFood;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            foodCuisine[food] = cuisine;
            foodRating[food] = rating;
            cuisineRatingFood[cuisine].insert({-rating,food}); 
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = foodRating[food];
        string cuisine = foodCuisine[food];
        foodRating[food] = newRating;
        cuisineRatingFood[cuisine].erase({-oldRating,food});
        cuisineRatingFood[cuisine].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto it = cuisineRatingFood[cuisine].begin();
        return it->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */