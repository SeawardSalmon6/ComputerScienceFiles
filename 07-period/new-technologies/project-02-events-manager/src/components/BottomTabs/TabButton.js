import { Pressable } from "react-native";

import Icon from "react-native-vector-icons/Octicons";
import { styles } from "./styles";

export function TabButton({ icon, onPress, currentIndex, index }) {
  return (
    <Pressable
      onPress={onPress}
      style={[styles.tabButton, currentIndex === index && styles.selected]}
    >
      <Icon name={icon} style={styles.icon} />
    </Pressable>
  );
}
