class Knapsack:
    item_list = []
    bag_capacity = 12  
    
    def __init__(self, item, weight, profit):
        self.item = item
        self.weight = weight
        self.profit = profit
        Knapsack.item_list.append([self.item, self.weight, self.profit])

    def per_weight_profit(self):
        if self.weight == 0:
            return 0
        return self.profit / self.weight 

    def bag(self):
        sorted_items = sorted(Knapsack.item_list, key=lambda x: x[2] / x[1], reverse=True)
        
        total_weight = 0
        total_profit = 0
        selected_items = []
        
        # Select items that fit within the knapsack's capacity
        for item in sorted_items:
            if total_weight + item[1] <= Knapsack.bag_capacity:
                selected_items.append(item)
                total_weight += item[1]
                total_profit += item[2]
            else:
                remaining_capacity = Knapsack.bag_capacity - total_weight
                fraction = remaining_capacity / item[1]
                profit_from_fraction = item[2] * fraction
                selected_items.append([item[0], remaining_capacity, profit_from_fraction])
                total_weight += remaining_capacity
                total_profit += profit_from_fraction
                break 
        
        return selected_items, total_weight, total_profit


item1 = Knapsack("Item1", 2, 40) 
item2 = Knapsack("Item2", 8, 50)
item3 = Knapsack("Item3", 10, 60)


selected_items, total_weight, total_profit = item1.bag()


print("Selected Items:")
for item in selected_items:
    print(f"Item: {item[0]}, Weight: {item[1]}, Profit: {item[2]}")

print(f"\nTotal Weight: {total_weight}")
print(f"Total Profit: {total_profit}")
