import { useContext } from "react";
import { TasksContext } from "./Provider";

export function useTasksContext() {
  return useContext(TasksContext);
}
