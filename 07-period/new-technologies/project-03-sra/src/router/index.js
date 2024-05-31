import { HomeScreen } from "@/screens/Home";
import { LoginScreen } from "@/screens/Login";
import { ForgotPasswordScreen } from "@/screens/Login/ForgotPassword";
import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";

const Stack = createNativeStackNavigator();

function LoginStack() {
  return (
    <Stack.Navigator
      initialRouteName="Login"
      screenOptions={{ headerShown: false, animation: "ios" }}
    >
      <Stack.Screen name="Login" component={LoginScreen} />
      <Stack.Screen name="ForgotPassword" component={ForgotPasswordScreen} />
    </Stack.Navigator>
  );
}

export function RouterProvider() {
  return (
    <NavigationContainer>
      <LoginStack />
    </NavigationContainer>
  );
}
