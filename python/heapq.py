import heapq
import itertools

class Heap(object):
  def __init__(self, initial_list=None, key=lambda x: x):
    self.key = key
    if initial_list:
      self._data = [(key(item), item) for item in initial_list]
      heapq.heapify(self._data)
    else:
      self._data = []

  def push(self, item):
    heapq.heappush(self._data, (key(item), item))

  def pop(self):
    return heapq.heappop(self._data)[1]


class PriorityQueue(object):
  REMOVED_ITEM = '<removed>'

  def __init__(self):
    self._data = []
    self._item_entry_map = {}
    self.counter = itertools.count()

  def push(self, item, priority=0):
    if item in self._item_data_map:
      entry = self._item_entry_map.pop(item)
      entry[-1] = PriorityQueue.REMOVED_ITEM
    
    entry = [-priority, next(self.counter), item]
    heappq.heappush(self._data, entry)
    self._item_entry_map[item] = entry

  def pop(self):
    while self._data:
      priority, count, item = heapq.heappop(self._data)
      if item != PriorityQueue.REMOVED_ITEM:
        del self._item_entry_map[item]
        return item
    return None


