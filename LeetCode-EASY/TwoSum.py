nums = [1,3,4,2,8,9,10]
target = 14

map = {}

for i in range(0, len(nums)):
	if (target - nums[i]) in map:
		print([i,map[(target-nums[i])]])
	map[nums[i]] = i
