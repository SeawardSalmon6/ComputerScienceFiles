import { NavigationContainer } from "@react-navigation/native";
import { Home } from "../screens/Home";
import { Events } from "../screens/Events";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";
import { BottomTabs } from "../components/BottomTabs";
import { createNativeStackNavigator } from "@react-navigation/native-stack";
import { EditEvent } from "../screens/Events/EditEvent";

const Stack = createNativeStackNavigator();
const Tabs = createBottomTabNavigator();

function StackNavigator() {
  return (
    <Stack.Navigator screenOptions={{ headerShown: false, animation: "ios" }}>
      <Stack.Screen name="EventsScreen" component={Events} />
      <Stack.Screen name="EditEvent" component={EditEvent} />
    </Stack.Navigator>
  );
}

function TabsNavigator() {
  return (
    <Tabs.Navigator
      initialRouteName="Home"
      screenOptions={{ headerShown: false, animation: "ios" }}
      tabBar={(props) => <BottomTabs {...props} />}
    >
      <Tabs.Screen name="Home" component={Home} />
      <Tabs.Screen name="Events" component={StackNavigator} />
    </Tabs.Navigator>
  );
}

export function RouterProvider() {
  return (
    <NavigationContainer>
      <TabsNavigator />
    </NavigationContainer>
  );
}
