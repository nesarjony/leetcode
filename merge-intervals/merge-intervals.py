from functools import cmp_to_key

class Solution:
    
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        mark = [0 for i in range(50)]
        
        intervals.append([10005, 10005])
        
        def compare(item1, item2):
            if item1[0] == item2[0]:
                return item1[1] - item2[1]
            return item1[0] - item2[0]
        
        intervals = sorted(intervals, key=cmp_to_key(compare))
        results = []
        start = intervals[0][0]
        end = intervals[0][1]
        for i in range(0, len(intervals) , 1):
            if intervals[i][0] <= end:
                end = max(intervals[i][1], end)
            else:
                results.append([start, end])
                start = intervals[i][0]
                end = intervals[i][1]
                
        return results