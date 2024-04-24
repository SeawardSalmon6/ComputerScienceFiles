export const actions = {
  delete(users, action) {
    const { user } = action;
    const updatedUsers = users.filter((u) => u.id !== user.id);
    return updatedUsers;
  },

  create(users, action) {
    const { user } = action;
    const newUserId = Math.max(...users.map((u) => u.id)) + 1;
    const updatedUsers = users.concat({ ...user, id: newUserId });
    return updatedUsers;
  },

  update(users, action) {
    const { user: updatedUser } = action;
    const updatedUsers = users.map((user) =>
      user.id === updatedUser.id ? { ...user, ...updatedUser } : user
    );
    return updatedUsers;
  },
};

export const usersReducer = (state, action) => {
  const actionFn = actions[action.type];
  return actionFn ? actionFn(state, action) : state;
};
