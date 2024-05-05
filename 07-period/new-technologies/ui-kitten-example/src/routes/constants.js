const TAB_ROUTE_PREFIX = "Tab__";

export const getTabInitialRouteName = (name) => {
  return `${TAB_ROUTE_PREFIX}${name}`;
};
