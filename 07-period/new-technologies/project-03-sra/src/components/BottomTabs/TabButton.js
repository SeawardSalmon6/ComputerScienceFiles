import { Image, Pressable } from "react-native";
import { styles } from "./styles";

const ICONS = {
  qr_code: require("@/assets/images/qr_code.png"),
  settings: require("@/assets/images/settings.png"),
  trophy: require("@/assets/images/trophy.png"),
};

export function TabButton({ icon, iconStyle, onPress, containerStyle }) {
  return (
    <Pressable onPress={onPress} style={[styles.tabButton, containerStyle]}>
      <Image
        style={[styles.icon, iconStyle]}
        resizeMode="contain"
        source={ICONS[icon]}
      />
    </Pressable>
  );
}
