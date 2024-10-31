import { BottomTabs } from "@/components/BottomTabs";
import { useAuthContext } from "@/contexts/AuthContext/useAuthContext";
import { HomeScreen } from "@/screens/Home";
import { LoginScreen } from "@/screens/Login";
import { ConfirmationCodeScreen } from "@/screens/Login/ConfirmationCode";
import { ConfirmationSplashScreen } from "@/screens/Login/ConfirmationCodeSplash";
import { ForgotPasswordScreen } from "@/screens/Login/ForgotPassword";
import { RegisterScreen } from "@/screens/Login/Register";
import { RegisterFinalScreen } from "@/screens/Login/RegisterFinal";
import { SettingsScreen } from "@/screens/Settings";
import { AccountSettingsScreen } from "@/screens/Settings/Account";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";
import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";

const Stack = createNativeStackNavigator();
const Tabs = createBottomTabNavigator();

function SettingsStack() {
  return (
    <Stack.Navigator
      initialRouteName="GeneralSettings"
      screenOptions={{ animation: "ios", headerShown: false }}
    >
      <Stack.Screen name="GeneralSettings" component={SettingsScreen} />
      <Stack.Screen name="AccountSettings" component={AccountSettingsScreen} />
    </Stack.Navigator>
  );
}

function HomeBottomTabs() {
  const { user } = useAuthContext();

  return (
    <Tabs.Navigator
      initialRouteName="HomeScreen"
      screenOptions={{ headerShown: false }}
      tabBar={(props) => <BottomTabs {...props} />}
    >
      <Tabs.Screen name="HomeScreen" component={HomeScreen} />
    </Tabs.Navigator>
  );
}

function AppStack() {
  const { user } = useAuthContext();

  return (
    <Stack.Navigator
      initialRouteName="Login"
      screenOptions={{ headerShown: false, animation: "ios" }}
    >
      <Stack.Screen name="Login" component={LoginScreen} />
      <Stack.Screen name="Home" component={HomeBottomTabs} />
      <Stack.Screen name="Settings" component={SettingsStack} />
      <Stack.Screen name="ForgotPassword" component={ForgotPasswordScreen} />
      <Stack.Screen name="Register" component={RegisterScreen} />
      <Stack.Screen name="RegisterFinal" component={RegisterFinalScreen} />
      <Stack.Screen
        name="ConfirmationSplash"
        component={ConfirmationSplashScreen}
      />
    </Stack.Navigator>
  );
}

export function RouterProvider() {
  return (
    <NavigationContainer>
      <AppStack />
    </NavigationContainer>
  );
}
