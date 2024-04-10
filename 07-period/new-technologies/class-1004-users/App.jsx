import { StatusBar } from "expo-status-bar";
import { SafeAreaView, StyleSheet } from "react-native";
import { Routes } from "./src/routes/router";
import { SafeAreaProvider } from "react-native-safe-area-context";
import { UsersProvider } from "./src/contexts/UsersContext/Provider";

export default function App() {
  return (
    <SafeAreaProvider>
      <UsersProvider>
        <Routes />
      </UsersProvider>
    </SafeAreaProvider>
  );
}
