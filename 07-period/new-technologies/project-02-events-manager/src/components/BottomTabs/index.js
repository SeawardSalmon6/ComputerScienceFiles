import { View } from "react-native";
import { TabButton } from "./TabButton";
import { styles } from "./styles";
import { useAppNavigation } from "../../hooks/useAppNavigation";

export function BottomTabs({ state }) {
  const { getGoTo } = useAppNavigation();
  const { index } = state;

  return (
    <View style={styles.container}>
      <View style={styles.contentContainer}>
        <TabButton
          currentIndex={index}
          index={0}
          onPress={getGoTo("Home")}
          icon="home"
        />
        <View style={styles.divider} />
        <TabButton
          currentIndex={index}
          index={1}
          onPress={getGoTo("Events")}
          icon="gear"
        />
      </View>
    </View>
  );
}
