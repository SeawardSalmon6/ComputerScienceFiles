import { Pressable } from "react-native";
import { BodyText } from "../BodyText";
import styles from "./styles";

export function Button({ disabled, onPress, children, style }) {
  return (
    <Pressable
      disabled={disabled}
      onPress={onPress}
      style={{
        ...styles.button,
        ...(disabled ? styles.disabled : undefined),
        ...style,
      }}
    >
      <BodyText style={styles.buttonText}>{children}</BodyText>
    </Pressable>
  );
}
