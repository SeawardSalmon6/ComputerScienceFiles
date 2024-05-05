import { NavigationContainer } from "@react-navigation/native";
import { APP_ROUTES } from "./app.routes";
import { HomeScreen } from "../screens/Home";
import { DetailsScreen } from "../screens/Details";
import { createBottomTabNavigator } from "@react-navigation/bottom-tabs";
import { MAIN_BOTTOM_TAB_OPTIONS } from "../shared/mainBottomTabOptions";
import { AppLayout } from "../components/AppLayout";

const Tab = createBottomTabNavigator();

export function RouterProvider() {
  return (
    <NavigationContainer>
      <Tab.Navigator
        screenOptions={{ headerShown: false }}
        tabBar={(props) => (
          <AppLayout.BottomTab
            options={MAIN_BOTTOM_TAB_OPTIONS}
            floating
            {...props}
          />
        )}
        initialRouteName={APP_ROUTES.HOME}
      >
        <Tab.Screen name={APP_ROUTES.HOME} component={HomeScreen} />
        <Tab.Screen name={APP_ROUTES.DETAILS} component={DetailsScreen} />
      </Tab.Navigator>
    </NavigationContainer>
  );
}
