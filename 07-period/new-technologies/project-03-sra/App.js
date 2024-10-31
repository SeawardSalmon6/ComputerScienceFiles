import { ThemeProvider } from "@/contexts/ThemeContext/Provider";
import { RouterProvider } from "@/router";
import { StatusBar } from "expo-status-bar";
import { SafeAreaProvider } from "react-native-safe-area-context";
import * as SplashScreen from "expo-splash-screen";
import { useFonts } from "expo-font";
import { useCallback } from "react";
import { useThemeContext } from "@/contexts/ThemeContext/useThemeContext";
import { AuthProvider } from "@/contexts/AuthContext/Provider";

SplashScreen.preventAutoHideAsync();

function App() {
  const { statusBarStyle } = useThemeContext();

  return (
    <>
      <RouterProvider />
      <StatusBar style={statusBarStyle} />
    </>
  );
}

export default function AppEntryComponent() {
  const [fontsLoaded, fontError] = useFonts({
    "Inter-Black": require("./src/assets/fonts/Inter/Inter-Black.ttf"),
    "Inter-Bold": require("./src/assets/fonts/Inter/Inter-Bold.ttf"),
    "Inter-ExtraBold": require("./src/assets/fonts/Inter/Inter-ExtraBold.ttf"),
    "Inter-ExtraLight": require("./src/assets/fonts/Inter/Inter-ExtraLight.ttf"),
    "Inter-Light": require("./src/assets/fonts/Inter/Inter-Light.ttf"),
    "Inter-Medium": require("./src/assets/fonts/Inter/Inter-Medium.ttf"),
    "Inter-Regular": require("./src/assets/fonts/Inter/Inter-Regular.ttf"),
    "Inter-SemiBold": require("./src/assets/fonts/Inter/Inter-SemiBold.ttf"),
    "Inter-Thin": require("./src/assets/fonts/Inter/Inter-Thin.ttf"),
  });

  const onLayoutRootView = useCallback(async () => {
    if (fontsLoaded || fontError) {
      await SplashScreen.hideAsync();
    }
  }, [fontsLoaded, fontError]);

  if (!fontsLoaded && !fontError) {
    return null;
  }

  return (
    <SafeAreaProvider onLayout={onLayoutRootView}>
      <ThemeProvider>
        <AuthProvider>
          <App />
        </AuthProvider>
      </ThemeProvider>
    </SafeAreaProvider>
  );
}
