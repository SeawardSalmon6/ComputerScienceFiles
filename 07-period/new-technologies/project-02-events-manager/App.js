import { StatusBar } from "expo-status-bar";
import { RouterProvider } from "./src/routes/router";
import { EventsContextProvider } from "./src/contexts/Events/Provider";
import { SafeAreaProvider } from "react-native-safe-area-context";

export default function App() {
  return (
    <>
      <SafeAreaProvider>
        <EventsContextProvider>
          <RouterProvider />
        </EventsContextProvider>
      </SafeAreaProvider>
      <StatusBar style="light" />
    </>
  );
}
