export const actions = {
  delete(tasks, action) {
    const { user: task } = action;
    const updatedTasks = tasks.filter((t) => t.id !== task.id);
    return updatedTasks;
  },

  create(tasks, action) {
    const { task: newTask } = action;
    const newTaskId = Math.max(...tasks.map((task) => task.id)) + 1;
    const updatedTasks = tasks.concat({ ...newTask, id: newTaskId });
    return updatedTasks;
  },

  update(tasks, action) {
    const { task: updatedTask } = action;
    const updatedTasks = tasks.map((task) =>
      task.id === updatedTask.id ? { ...task, ...updatedTask } : task
    );
    return updatedTasks;
  },
};

export const tasksReducer = (state, action) => {
  const actionFn = actions[action.type];
  return actionFn ? actionFn(state, action) : state;
};
