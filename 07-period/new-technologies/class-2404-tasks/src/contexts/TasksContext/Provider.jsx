import { createContext, useMemo, useReducer } from "react";
import { tasksReducer } from "./constants";

export const TasksContext = createContext({
  tasks: [],
  tasksDispatcher: () => {},
});

export function TasksProvider({ children }) {
  const [tasks, tasksDispatcher] = useReducer(tasksReducer, []);

  const value = useMemo(
    () => ({
      tasks,
      tasksDispatcher,
    }),
    [tasks, tasksDispatcher]
  );

  return (
    <TasksContext.Provider value={value}>{children}</TasksContext.Provider>
  );
}
