import { BottomNavigation, BottomNavigationTab } from "@ui-kitten/components";
import { useAppNavigation } from "../../hooks/useAppNavigation";
import { styles } from "./styles";
import { View } from "react-native";

export function BottomTab({ state, options, floating = false }) {
  const { index, routeNames } = state;
  const { goTo } = useAppNavigation();

  const routeName = routeNames[index];
  const currentIndex = options.findIndex(
    (option) => option.screenName === routeName
  );

  const onSelect = (index) => {
    const option = options[index];
    if (option.screenName) {
      goTo(option.screenName);
    }
  };

  return (
    <View
      style={{
        ...styles.bottomNavigationContainer,
        ...(floating ? styles.bottomNavigationFloatingContainer : {}),
      }}
    >
      <BottomNavigation
        selectedIndex={currentIndex === -1 ? 0 : currentIndex}
        onSelect={onSelect}
        indicatorStyle={{
          ...styles.bottomNavigationIndicator,
          ...(floating ? styles.bottomNavigationFloatingIndicator : {}),
        }}
        style={{
          ...styles.bottomNavigation,
          ...(floating ? styles.bottomNavigationFloating : {}),
        }}
      >
        {options.map((option) => (
          <BottomNavigationTab
            key={option.key}
            icon={option.icon}
            style={option.style}
          />
        ))}
      </BottomNavigation>
    </View>
  );
}
