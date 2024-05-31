export function getNextId(list, key = "id") {
  const parsedList = list.map((item) => parseInt(item[key], 10));
  return Math.max(...parsedList, 0) + 1;
}
