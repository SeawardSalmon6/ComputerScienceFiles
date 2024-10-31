import { View } from "react-native";
import { TabButton } from "./TabButton";
import { styles } from "./styles";
import { useAppNavigation } from "../../hooks/useAppNavigation";

export function BottomTabs() {
  const { getGoTo } = useAppNavigation();

  return (
    <View style={styles.container}>
      <View style={styles.contentContainer}>
        {/* <TabButton onPress={getGoTo("Ranking")} icon="trophy" /> */}
        <TabButton
          icon="qr_code"
          containerStyle={{
            paddingVertical: 0,
            paddingHorizontal: 0,
          }}
          iconStyle={{
            height: 72,
            transform: [{ translateY: -10 }],
          }}
        />
        <TabButton onPress={getGoTo("Settings")} icon="settings" />
      </View>
    </View>
  );
}
