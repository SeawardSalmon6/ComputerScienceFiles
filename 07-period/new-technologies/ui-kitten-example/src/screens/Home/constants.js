export const ADD_ITEM_KEY = "new_item";

export const BASE_ITEMS = [
  {
    key: "1",
    title: "Item 1",
    is_favorite: true,
  },
  {
    key: "2",
    title: "Item 2",
    is_favorite: false,
  },
  {
    key: "3",
    title: "Item 3",
    is_favorite: false,
  },
];

export const getNextKey = (items) => {
  const keys = items.map(({ key }) => parseInt(key));
  return String(Math.max(...keys) + 1);
};
