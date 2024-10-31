import { APP_COLORS } from "@/assets/theme";
import styles from "@/components/Card/styles";
import { Text, View } from "react-native";

export function Card({
  containerStyle,
  titleContainerStyle,
  title,
  subtitle,
  children,
  titleStyle,
  backgroundColor = APP_COLORS.white,
}) {
  return (
    <View style={[styles.container, { backgroundColor }, containerStyle]}>
      {(title || subtitle) && (
        <View style={[styles.titleContainer, titleContainerStyle]}>
          {title && <Text style={[styles.title, titleStyle]}>{title}</Text>}
          {subtitle && <Text style={styles.subtitle}>{subtitle}</Text>}
        </View>
      )}
      {children}
    </View>
  );
}
