import { Button } from "@/components/Button";
import { Form } from "@/components/Form";
import { Input } from "@/components/Input";
import { useAppNavigation } from "@/hooks/useAppNavigation";
import { LoginLayout } from "@/screens/Login/components/LoginLayout";
import styles from "@/screens/Login/styles";
import { isAllFieldsFilled } from "@/utils/isAllFieldsFilled";
import { useRoute } from "@react-navigation/native";
import { useEffect, useState } from "react";
import { Controller, useForm } from "react-hook-form";
import { Text } from "react-native";

const FORM_FIELDS = [["code", (value) => value.length === 4]];

export function ConfirmationCodeScreen() {
  const { params } = useRoute();
  const { values } = params ?? {};

  const [isButtonDisabled, setIsButtonDisabled] = useState(true);
  const { getGoTo } = useAppNavigation();

  const { watch, control, setValue } = useForm();
  watch((values) => {
    setIsButtonDisabled(!isAllFieldsFilled(values ?? {}, FORM_FIELDS));
  });

  useEffect(() => {
    if (values) {
      Object.entries(values).forEach(([key, value]) => {
        setValue(key, value);
      });
    }
  }, []);

  return (
    <LoginLayout
      title="enviei um código no seu e-mail"
      subtitle="vê lá, é rapidinho"
    >
      <Form>
        <Controller
          control={control}
          name="code"
          render={({ field: { value, onChange } }) => (
            <Input type="code" value={value} onChange={onChange} />
          )}
        />
        <Text style={[styles.tip, { textAlign: "center" }]}>
          reenviar? clique aqui
        </Text>
        <Button
          onPress={getGoTo("ConfirmationSplash")}
          disabled={isButtonDisabled}
        >
          verificar
        </Button>
      </Form>
    </LoginLayout>
  );
}
