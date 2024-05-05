import { Routes } from "./src/routes/router";
import { SafeAreaProvider } from "react-native-safe-area-context";
import { TasksProvider } from "./src/contexts/TasksContext/Provider";

export default function App() {
  return (
    <SafeAreaProvider>
      <TasksProvider>
        <Routes />
      </TasksProvider>
    </SafeAreaProvider>
  );
}
